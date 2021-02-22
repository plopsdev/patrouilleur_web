const fs = require('fs');
const express = require('express');
const cors = require('cors');
const app = express()
const server  = require('http').createServer(app);
const WebSocket = require('ws')

const wss = new WebSocket.Server( {server:server} )

// wss.send('hello')

const delay = (ms) => {
    return new Promise(resolve => {
        setTimeout(() => resolve(undefined), ms);
    });
};

wss.on('connection', function connection(ws) {
    console.log('new client has connected')
    let rawdata = fs.readFileSync('./data.json', 'utf-8'); //use this instead of require because require keeps data in cache
    ws.send(rawdata);
    let fsWait = false;
    fs.watch('./data.json', async (_event, filename) => {
        if (filename) {
            if (fsWait) return;
            fsWait = setTimeout(() => {
                fsWait = false;
            }, 10);
            console.log('fichier modifié');

            let rawdata;
            do {
                rawdata = fs.readFileSync('./data.json', 'utf-8'); //use this instead of require because require keeps data in cache
            } while(!rawdata || await delay(10));
            ws.send(rawdata);
        }
        
    });

    ws.on('message', function incoming(message) {
      console.log('received: %s', message);
      ws.send('Got ur message : ' + message);
    });
  
    
  });

app.use(cors());
app.use(express.json()); 

app.get('/', (req, res) => {
    let rawdata = fs.readFileSync('./data.json'); //use this instead of require because require keeps data in cache
    let dataJSON = JSON.parse(rawdata)
    res.send(dataJSON)
});



app.put('/:isManual', (req, res) => {
    const isManual = req.params.isManual;
    dataJSON.manual = isManual 
    let dataOUT = JSON.stringify(dataJSON)
    fs.writeFileSync('./data.json', dataOUT);
    res.send('ok')
})



server.listen(3002);
