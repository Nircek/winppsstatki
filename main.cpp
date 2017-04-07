#include <iostream>
#include "winppspc/winppspc.h"

using namespace std;
using namespace GitHub::Nircek;
int main()
{
    string host,user,pass;
    PPSReply reply(0,"");
    winppspc *pc=(winppspc*)false;
    do{
        if(pc){
            delete pc;
            cout<<"cathed "<<readPPSReplyType(reply.replyType)<<' '<<reply.reply<<'\n';
        }
        cout<<"PPS host: ";cin>>host;
        cout<<"Username: ";cin>>user;
        cout<<"Password: ";cin>>pass;
        cin.ignore();
        pc=new winppspc(host,user,pass);
    }while((reply=pc->push("on")).replyType!=good);

    cout << "Hello world!" << endl;
    return 0;
}
