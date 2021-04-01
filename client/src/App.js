import './App.css';
import Manual from './pages/Manual'
import { getData, updateData } from './services';
import {React, useState, useEffect, useCallback} from 'react';
import LinearProgressWithLabel from '@material-ui/core/LinearProgress';
import Alert from '@material-ui/lab/Alert';
import socket from './socket'

let thermicAlertCount = 0;
let soundAlertCount = 0;

const App = () => {

    const [sound, setSound] = useState(0)
    const [thermicArray, setThermicArray] = useState([])
    const [isManual, setIsManual] = useState (false)
    const [soundThresholdState, setSoundThresholdState] = useState (false)
    const [thermicThresholdState, setThermicThresholdState] = useState (false)


    const openListener = useCallback(() => {
        console.log('connected to WS Server');
    });

    const messageListener = useCallback((event) => {
        console.log('message from server', event.data);
        setThermicArray(JSON.parse(event.data).thermicArray);
        setSound(JSON.parse(event.data).sound);
        soundTrigger(sound);
        thermicTrigger(thermicArray)
    });

    const fetchData = async() => {
        let data = await getData()
        setSound(data.sound)
        setThermicArray(data.thermicArray)
        setIsManual(data.manual)
    }

    const soundTrigger = (sound) => {
        let sThreshold = 26
        if (sound>sThreshold){
            setSoundThresholdState(true);
            soundAlertCount ++;
            document.getElementById("soundAlertNumber").innerHTML = ("Nombre d'alertes sonores : " + soundAlertCount).bold();
        } else {
            setSoundThresholdState(false)
        }   
    }

    const thermicTrigger = (thermicArray) => {
        let tThreshold = 24
        for (let item of thermicArray){
            if (item>tThreshold){
                setThermicThresholdState(true);
                thermicAlertCount ++;
                document.getElementById("thermicAlertNumber").innerHTML = ("Nombre d'alertes thermiques : " + thermicAlertCount).bold();
                break
            } else {
                setThermicThresholdState(false)
            }   
        }
    }

    useEffect(() => {
        socket.addEventListener('open', openListener)
        socket.addEventListener('message', messageListener);

        return () => {
            socket.removeEventListener('open', openListener);
            socket.removeEventListener('message', messageListener);
        };
    }, [ openListener, messageListener ]);
    
    const colorGenerator = (tIn) => {
        let tMin = 20;
        let tMax = 35;
        let coef = 255/(tMax-tMin)
        let tProp = tIn-tMin 
        let colorValue = 255-tProp*coef
        return `#FF${colorValue.toString(16)}${colorValue.toString(16)}`
    }





    return(
        <>
            {isManual ? (
                <Manual
                    setIsManual = {setIsManual}
                />
            ) : (
            <div style = {{marginLeft: '50px'}}>
                <h1>Mode Automatique</h1>
                <LinearProgressWithLabel style={{maxWidth:'30%', marginBottom:'50px'}} variant='determinate'  value={sound} />
                {[0, 1, 2, 3].map((raw) => {
                    return(
                        <div className="row" key={raw}>
                            {thermicArray.map((thermic, index) => {
                                if (index>=raw*4 && index<(raw*4+4)){
                                    return <div key={index} style={{width:'30px', height: '30px', backgroundColor:colorGenerator(thermic)}}></div>
                                }
                            })}
                        </div>
                    )
                })}

                
                
                <div className = "camera">

                
                    <button style={{maxWidth: '150px', marginTop:'50px'}} onClick={()=> {
                        // await updateData(!isManual)
                        setIsManual(!isManual)
                    }}>
                        Mode Manuel
                    </button> 

                    <div id= "container">
                        {soundThresholdState ? (<div className="warn"><Alert severity="warning">This is a warning sound alert!</Alert></div>) : (<div className="warn"><h3>son OK</h3></div>)}
                        <div id="soundAlertNumber"></div>
                    </div>
                    <div id= "container">
                        {thermicThresholdState ? (<div className="warn"><Alert severity="error">This is a warning thermic alert !</Alert></div>) : (<div className="warn"><h3>temperature OK</h3></div>)}
                        <div id="thermicAlertNumber"></div>
                    </div>
                </div>
            </div>)}
        </>
    )
}
export default App;
