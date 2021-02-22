import './App.css';
import { getData, updateData } from './services';
import {React, useState, useEffect} from 'react';
// import LinearProgressWithLabel from '@material-ui/core/LinearProgress';
const socket = new WebSocket ('ws://localhost:3002')



const App = () => {

    const [sound, setSound] = useState(0)
    const [thermicArray, setThermicArray] = useState([])
    const [isManual, setIsManual] = useState (false)

    const fetchData = async() => {
        let data = await getData()
        setSound(data.sound)
        setThermicArray(data.thermicArray)
        setIsManual(data.manual)
    }

    const sendMessage = () => {
        socket.send('hello from client :)');
    }

    socket.addEventListener('open', function (event) {
        console.log('connected to WS Server')
    })
    
    socket.addEventListener('message', function (event) {
        console.log('message from server', event.data)
    })
    

    useEffect(() => {
        const timer = setInterval(() => {
          fetchData();
          //sendMessage();
        }, 10000);
    
        return () => {
          clearInterval(timer);
        };
      }, []);
    

    return(
        <div>
            {/* <LinearProgressWithLabel variant="determinate" value={sound} />  */}
            Sound : {sound}
            {[0, 1, 2, 3].map((raw) => {
                return(
                    <div className="row">
                        {thermicArray.map((thermic, index) => {
                            if (index>=raw*4 && index<(raw*4+4)){
                                return <div className={`index_${index}`}>{thermic}</div>
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
                {/* <img src="http://192.168.46.61:8081" alt="" /> */}
            </div>
        </div>
    )
}
export default App;
