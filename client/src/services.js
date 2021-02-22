import Axios from "axios"

const getData = () => {
    return Axios.get('http://localhost:3002/').then(response => response.data)
};

const updateData = (isManual) => {
    return Axios.put(`http://localhost:3002/${isManual}`)
};

export {
    getData,
    updateData
}