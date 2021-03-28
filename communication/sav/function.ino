
const byte numChars = 64;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing


//============

// variables to hold the parsed data
//char rbDirection = 'x';
int wheelLeft = 0;
int wheelRight = 0;
int other = 0;

//============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte i = 0;
    char startMarker = '<';
    char endMarker = '>';
    char message;

    while (Serial.available() > 0) {
        message = Serial.read();
        
        if (recvInProgress == true) {
            if (message != endMarker) {
                receivedChars[i] = message;
                i++;
                if (i >= numChars) {
                    i = numChars - 1;
                }
            }
            else {
                receivedChars[i] = '\0'; // terminate the string
                recvInProgress = false;
                i = 0;
            }
        }
        else if (message == startMarker) {
            recvInProgress = true;
        }
    }
}//============

void fillArray(int arr[]) {   
    recvWithStartEndMarkers(); // reçois les données
    strcpy(tempChars, receivedChars); // copie le second array dans le premier
    
    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");   // prend la première partie de l'array 
                                          //en le cassant en sous partie en fonction du délimiteur (ici ,).
    //strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    arr[0] = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    arr[1] = atoi(strtokIndx);  
      
    strtokIndx = strtok(NULL, ",");
    arr[2] = atoi(strtokIndx);     
/*
    strtokIndx = strtok(NULL, ",");
    Serial.print("stock:");
    Serial.println(strtokIndx);
     Serial.println("stockCONV : ");
     Serial.print((char)strtokIndx);
    
    //strcpy(rbDirection, strtokIndx);
    rbDirection = strtokIndx;
    
    Serial.print("   dire ");
    Serial.print(rbDirection);
    
    Serial.print("   dire2 ");
    Serial.println((int)rbDirection);
    
    arr[3] = (int)rbDirection; 
 */

}
