#include<iostream>
#include<string>
using namespace std;

class NotificationSystem 
{ 
    public:

  virtual void sendMessage( string Employee , string message ) = 0;

    void PolicyUpdate ()
    {
        cout<< "New Policy Announcement !!" << endl;
    }

    void GetReminder ()
    {
        cout<< "New reminder arrived !!" << endl;
    }
    
    void SystemAlert ()
    {
        cout<< "hey one alert found !" << endl;
    }

};

class EmailNotification : public NotificationSystem
{
    public :
    void sendMessage ( string Employee , string message)
    {
        cout<< Employee << ": recieved notification by a Email"<<endl; 
        cout<< message << endl;
    }
};
class SmsNotification : public NotificationSystem
{

     public :
    void sendMessage ( string Employee , string message)
    {
         cout<< Employee << ": recieved notification by a Sms"<<endl; 
        cout<< message << endl;
    }
};

class PushNotification : public NotificationSystem
{

     public :
    void sendMessage ( string Employee , string message)
    {
        cout<< Employee << ": recieved notification by a Push Notification"<<endl; 
        cout<< message << endl;
    }
};

int main ()
{
    NotificationSystem* notify;

    notify = new EmailNotification ();
    notify->sendMessage ("Parth" , "i hope this code run well !");
    notify -> PolicyUpdate ();
    notify -> GetReminder();
    notify -> SystemAlert();
    cout<<endl;

    notify = new SmsNotification ();
    notify->sendMessage ("Nikhil" , "I Hope this notification find you well !");
    notify -> PolicyUpdate ();
    notify -> GetReminder();
    notify -> SystemAlert();
    cout<<endl;

    notify = new PushNotification ();
    notify->sendMessage ("Abhijeet" , "I hope you doing well !");
    notify -> PolicyUpdate ();
    notify -> GetReminder();
    notify -> SystemAlert();
    cout<<endl;


}

