import React, {useState} from 'react'
import ColorArray from '../components/ColorArray';
import Alert from '@material-ui/lab/Alert';
import LinearProgress from '@material-ui/core/LinearProgress';

const Auto = ({sound, thermicArray, thermicThresholdState, soundThresholdState, setIsManual, isManual}) => {
    return(
        <div style = {{marginLeft: '50px'}}>
            <h1>Mode Automatique</h1>
            <LinearProgress style={{maxWidth:'30%'}} variant='determinate'  value={sound} />
            <div style={ {marginBottom:'50px'}}>{sound} %</div>
            <ColorArray thermicArray={thermicArray}/>
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
                    <div id="soundAlertValue"></div>
                </div>
                <div id= "container">
                    {thermicThresholdState ? (<div className="warn"><Alert severity="error">This is a warning thermic alert !</Alert></div>) : (<div className="warn"><h3>temperature OK</h3></div>)}
                    <div id="thermicAlertNumber"></div>
                    <div id="thermicAlertValue"></div>
                </div>
            </div>
        </div>
    )
}

export default Auto;