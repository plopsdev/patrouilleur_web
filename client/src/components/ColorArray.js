import React from 'react';

const colorGenerator = (tIn) => {
    let tMin = 20;
    let tMax = 35;
    let coef = 255/(tMax-tMin)
    let tProp = tIn-tMin 
    let colorValue = 255-tProp*coef
    return `#FF${colorValue.toString(16)}${colorValue.toString(16)}`
}

const ColorArray = ({thermicArray}) => {
    return(
        [0, 1, 2, 3].map((raw) => {
            return(
                <div className="row" key={raw}>
                    {thermicArray.map((thermic, index) => {
                        if (index>=raw*4 && index<(raw*4+4)){
                            return <div key={index} style={{width:'30px', height: '30px', backgroundColor:colorGenerator(thermic)}}></div>
                        }
                    })}
                </div>
            )
        })
    )
    
}

export default ColorArray