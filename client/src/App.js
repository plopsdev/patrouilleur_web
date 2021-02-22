import './App.css';
import { getData, updateData } from './services';
import {React, useState, useEffect, useCallback} from 'react';
// import LinearProgressWithLabel from '@material-ui/core/LinearProgress';
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
    

    return(
        <div>
            {/* <LinearProgressWithLabel variant="determinate" value={sound} />  */}
            Sound : {sound}
            {[0, 1, 2, 3].map((raw) => {
                return(
                    <div className="row" key={raw}>
                        {thermicArray.map((thermic, index) => {
                            if (index>=raw*4 && index<(raw*4+4)){
                                return <div className={`index_${index}`} key={index}>{thermic}</div>
                            }
                        })}
                    </div>
                )
            })}
            
            <div className = "camera">
                <button onClick={async()=> {
                    await updateData(!isManual)
                    setIsManual(!isManual)
                }}>
                    Mode Manuel
                </button> 
                {/* <img src="http://192.168.46.61:8081" alt="Stream" /> */}
            </div>
        </div>
    )
}
export default App;
