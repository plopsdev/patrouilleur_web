import './App.css';
import Manual from './pages/Manual';
import {React, useState, useEffect, useCallback} from 'react';
import socket from './socket'
import Auto from './pages/Auto';

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

    const soundTrigger = (sound) => {
        let sThreshold = 26
        if (sound>sThreshold){
            setSoundThresholdState(true);
            soundAlertCount ++;
            document.getElementById("soundAlertNumber").innerHTML = ("Nombre d'alertes sonores : " + soundAlertCount).bold();
            document.getElementById("soundAlertValue").innerHTML = ("Valeur sonore : " + sound).bold();
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
                document.getElementById("thermicAlertValue").innerHTML = ("Valeurs thermiques : " + thermicArray).bold();
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

    return(
        <>
            {isManual ? (
                <Manual setIsManual = {setIsManual}/>
            ) : (
                <Auto
                    isManual = {isManual}
                    setIsManual = {setIsManual}
                    soundThresholdState = {soundThresholdState}
                    thermicThresholdState = {thermicThresholdState}
                    sound = {sound}
                    thermicArray = {thermicArray}
                />
            )}
        </>
    )
}
export default App;
