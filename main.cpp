#include <iostream>
#include "winppspc/winppspc.h"

using namespace std;
using namespace GitHub::Nircek;
int main()
{
    string action,host,user,pass;
    bool cont;
    winppspc *pc=(winppspc*)false;
    do{
        cont=false;
        if(pc){
            delete pc;
        }
        cout<<"\nPPS host: ";cin>>host;
        cout<<"1)Login\n2)Register\n";
        do{
            cin>>action;
        }while((action!="1")&&(action!="2"));
        cout<<"Username: ";cin>>user;
        cout<<"Password: ";cin>>pass;
        cin.ignore();
        if(action=="1"){
            pc=new winppspc(host,user,pass);
        }else{
            pc=new winppspc(host);
            if(readerror(pc->uregister(user,pass)).replyType!=good)cont=true;
        }
    }while(cont?true:readerror(pc->push("on")).replyType!=good);

    cout << "Hello world!" << endl;
    delete pc;
    return 0;
}
