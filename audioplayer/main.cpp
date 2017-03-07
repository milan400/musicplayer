#include <iostream>
#include <iomanip>
#include<Windows.h>
#include"MMSystem.h"
#include<conio.h>
#include<fstream>
#include<sstream>

using namespace std;

void finfo();

class music{

private:
    char name[10];
    string artist;
    int dor;

public:
    void info();
    void detail();
    void play();
    void ifile();
    void ofile();

};

void music::info(){

    cout<<endl<<setw(50)<<endl<<"Welcome to MXAudio Player"<<endl;

    for(int i=0;i<3;i++)
        cout<<endl;

    cout<<endl<<setw(29)<<"Here are your options: "<<endl;
    cout<<endl<<setw(30)<<"Press 1 to add new song "<<endl;
    cout<<setw(27)<<"Press 2 to play song "<<endl;
    cout<<endl<<setw(14)<<"Option: ";
}
//detail about music and artist
void music::detail(){

    system("cls");
    cout<<endl<<setw(30)<<"Enter the song name: ";
    cin>>name;
    cout<<endl<<setw(36)<<"enter the date of release: ";
    cin>>dor;
    cin.ignore();
    cout<<endl<<setw(35)<<"Enter the name of artist: ";
    getline(cin,artist);

}

//function to play song
void music::play(){

    //system("cls");
    char song[20];
    cout<<endl<<"enter the name of song you want to play: ";
    cin>>song;
    char r[] = "../music/";
    PlaySound(TEXT(strcat(r,strcat(song,".wav"))),NULL,SND_SYNC);
    system("pause");

}
void music::ifile(){
    fstream tofile;
    tofile.open("detail.txt",fstream::app | fstream::out);
    tofile<<name<<"\t"<<"\t"<<"\t"<<artist<<"\t"<<"\t"<<"\t"<<dor<<endl;
    tofile.close();
}
void music::ofile(){
    ifstream infile;
    infile.open("detail.txt");

    stringstream strStream;

    //read the file
    strStream<<infile.rdbuf();

    //content holds the content of the file
    string content = strStream.str();
    cout<<endl<<content<<endl;

    infile.close();

}
int main()
{
    music m;

    m.info();
    int key;

    cin>>key;

    while(key!=0){
    switch(key){
        case 1:
            m.detail();
            m.ifile();
            system("cls");

            finfo();
            cin>>key;

            break;

        case 2:
            system("cls");
            m.ofile();
            m.play();
            break;
    }
    }
    return 0;
}

void finfo(){
            cout<<endl<<setw(49)<<"Want to add more song or play song or quit"<<endl;
            cout<<endl<<endl<<setw(21)<<"Options: "<<endl;
            cout<<endl<<setw(30)<<"1 to add more song"<<endl<<setw(21)<<"2 to play"<<endl<<setw(21)<<"0 to quit"<<endl;
            cout<<endl<<setw(20)<<"Choice: ";
}
