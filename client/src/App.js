import './App.css';
import { getData } from './services';
import {React, useState, useEffect} from 'react';
// import LinearProgressWithLabel from '@material-ui/core/LinearProgress';

const App = () => {

    const [sound, setSound] = useState(0)
    const [thermicArray, setThermicArray] = useState([])
    const [isManual, setIsManual] = useState (false)

    const fetchData = async() => {
        let data = await getData()
        setSound(data.sound)
        setThermicArray(data.thermicArray)
        setIsManual(data.isManual)
    }

    useEffect(() => {
        const timer = setInterval(() => {
          fetchData();
        }, 500);
    
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
                    <div className={'raw'}>
                        {thermicArray.map((thermic, index) => {
                            if (index>=raw*4 && index<(raw*4+4)){
                                return <div className={`index_${index}`}>{thermic}</div>
                            }
                            
                        })}
                    </div>
                )
            })}
            
        </div>
    )
}
export default App;
