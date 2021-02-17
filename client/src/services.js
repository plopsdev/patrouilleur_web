import Axios from "axios"

const getData = () => {
    return Axios.get('http://192.168.1.13:3002/').then(response => response.data)
}

export {
    getData
}