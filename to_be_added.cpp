/*---------------------------------- ajouter dans le constructeur de votre mainwindow .cpp ( ou le nomm de votre ui.cpp)
int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(connect_rfid())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données)
