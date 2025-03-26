#include<iostream>
using namespace std;
class Device{
protected:
int deviceID;
string deviceName;
bool status;
public:
Device(int id,string name,bool st):deviceID(id),deviceName(name),status(st){}
virtual void turnOn(){
    status = true;
}
virtual void turnOff(){
    status = false;
}
 virtual bool getStatus() const{
    return status;
}
virtual void displayInfo()const{
cout<<"NAME: "<<deviceName<<endl;
cout<<"ID: "<<deviceID<<endl;
cout<<"STATUS: "<<getStatus()<<endl;
}

};
class Light : public Device{
    protected:
    float brightnessLevel;
    string colorMode;
    string location;
    public:
    Light(int id,string name,bool st,float bl,string cm,string location):Device(id,name,st),brightnessLevel(bl),colorMode(cm),location(location){}
    void displayInfo()const{
        Device::displayInfo();
        cout<<"BRIGHTNESS LEVEL: "<<brightnessLevel<<endl;
        cout<<"COLOR MODE: "<<colorMode<<endl;
        cout<<"LOCATION: "<<location<<endl;
    }
};

class Thermostat : public Device{
    protected:
    float temperature;
    float targetTemperature;
    string mode;
    public:
    Thermostat(int id,string name,bool st,float temperature,float targetTemperature,string mode):Device(id,name,st),temperature(temperature),targetTemperature(targetTemperature),mode(mode){}
    bool getStatus()const{
        return temperature == targetTemperature;
    }
};
class SecurityCamera:public Device{
    protected:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
    public:
    SecurityCamera(int id,string name,bool st,string resolution,bool recordingStatus,bool nightVisionEnabled):Device(id,name,st),resolution(resolution),recordingStatus(recordingStatus),nightVisionEnabled(nightVisionEnabled){}
    void turnOn(){
        recordingStatus = true;
    }

};
class SmartPlug:public Device{
    protected:
    float powerComsumption;
    bool timerSettings;
    public:
    SmartPlug(int id,string name,bool st,float powerComsumption,bool timerSettings):Device(id,name,st),powerComsumption(powerComsumption),timerSettings(timerSettings){}
    void turnOff(){

        cout<<"LOGGING OFF..."<<endl;
        cout<<"POWER CONSUMPTION: "<<powerComsumption<<endl;
        cout<<"TIMER SETTINGS: "<<timerSettings<<endl;

    }

};
int main(){
SmartPlug *p = new SmartPlug(2,"OSAKA",true,500,true);
Light *l = new Light(2,"OSAKA",true,100,"CYAN","SW");
SecurityCamera *sc = new SecurityCamera(2,"OSAKA",true,"1080P",true,false);
Thermostat *t = new Thermostat (2,"OSAKA",false,60,60,"COOLING");

Device *k = l; 

k->displayInfo();

k = t;

cout<<k->getStatus()<<endl;

k = sc;

k->turnOn();

k = p;

k->turnOff();

delete l;
delete p;
delete sc;
delete t;
return 0;
}