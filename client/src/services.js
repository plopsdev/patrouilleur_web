import Axios from "axios"

const getData = () => {
    return Axios.get('http://localhost:3002/').then(response => response.data)
}

export {
    getData
}