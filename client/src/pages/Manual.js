import React  from 'react'
import {useEffect, useState} from 'react'
import socket from '../socket'

const Manual = ({setIsManual}) => {
    function useKey(key) {
        // Keep track of key state
        const [pressed, setPressed] = useState(false)
    
        // Does an event match the key we're watching?
        const match = event => key.toLowerCase() == event.key.toLowerCase()
    
        // Event handlers
        const onDown = event => {
            if (match(event) && event.repeat === false){
                console.log(event)
                setPressed(true)
                let message = (key + '_down')
                socket.send(message)
            } 
        }
    
        const onUp = event => {
            if (match(event) && event.repeat === false) {
                setPressed(false)
                let message = (key +'_up')
                socket.send(message)
            }
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

    useKey('z')
    useKey('q')
    useKey('s')
    useKey('d')
    return(
        <div style={{display: 'flex', flexDirection:'column', marginLeft: '50px'}}>
            <h1>Mode Manuel</h1>
            <img src="http://192.168.46.61:8081" alt="Stream" />
                <button style={{maxWidth: '150px'}} onClick={()=> {
                        // await updateData(!isManual)
                        socket.send("stop")
                        setIsManual(false)
                    }}>
                        Mode Automatique
                </button> 
         </div>
    )
}

export default Manual;