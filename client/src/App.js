import './App.css';
import { getData, updateData } from './services';
import {React, useState, useEffect, useCallback} from 'react';
import LinearProgressWithLabel from '@material-ui/core/LinearProgress';
const socket = new WebSocket ('ws://localhost:3002')



const App = () => {

    const [sound, setSound] = useState(0)
    const [thermicArray, setThermicArray] = useState([])
    const [isManual, setIsManual] = useState (false)

    const openListener = useCallback(() => {
        console.log('connected to WS Server');
    });

    const messageListener = useCallback((event) => {
        console.log('message from server', event.data);
        setThermicArray(JSON.parse(event.data).thermicArray);
        setSound(JSON.parse(event.data).sound);
    });

    const fetchData = async() => {
        let data = await getData()
        setSound(data.sound)
        setThermicArray(data.thermicArray)
        setIsManual(data.manual)
    }

    const sendMessage = () => {
        socket.send('hello from client :(');
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

    function useKey(key) {
        // Keep track of key state
        const [pressed, setPressed] = useState(false)
    
        // Does an event match the key we're watching?
        const match = event => key.toLowerCase() == event.key.toLowerCase()
    
        // Event handlers
        const onDown = event => {
            if (match(event)) setPressed(true)
        }
    
        const onUp = event => {
            if (match(event)) setPressed(false)
        }
    
        // Bind and unbind events
        useEffect(() => {
            window.addEventListener("keydown", onDown)
            window.addEventListener("keyup", onUp)
            return () => {
                window.removeEventListener("keydown", onDown)
                window.removeEventListener("keyup", onUp)
            }
        }, [key])
    
        return pressed
    }

    const zKey = useKey('z')
    console.log(zKey)

    return(
        <>
            {isManual ? (
            <div style={{display: 'flex', flexDirection:'column', marginLeft: '50px'}}>
                <h1>Mode Manuel</h1>
                
                <img src="http://192.168.46.61:8081" alt="Stream" />
                <button style={{maxWidth: '150px'}} onClick={()=> {
                        // await updateData(!isManual)
                        setIsManual(!isManual)
                    }}>
                        Mode Automatique
                </button> 
            </div>) : (
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
                    
                </div>
            </div>)}
        </>
    )
}
export default App;
