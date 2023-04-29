void MainWindow::connect_RFID()

{
    // pour tester si la connexion lors du passage de la carte rfid a ete effectué ou non avec un label 'RFID_Label'
    //ui->RFID_Label->setText("arduino detecte");

    data=A.read_from_arduino();
    QString uid = QTextCodec::codecForMib(106)->toUnicode(data);

    qDebug()<<uid;//pour tester dans la console de QT

    //ui->RFID_Label->setText(uid);/*------- pour tester avec un label----------*/

    Employe E; //remplacez avec le nom de votre classe

     // cas ou elle n'existe 
    if(E.rfidExists(uid))

        {

            QByteArray data1;
            data1.append('1');
            A.write_to_arduino(data1);//envoie 1 a arduino et enclenche /demarre le processus 1

            qDebug()<<"carte existante";

            //prend la valeur du nom
            QString nom = E.rfidName(uid);
            //ui->RFID_NOM->setText(nom);
            //ui->stackedWidget->setCurrentIndex(2); redirige ves la page 3 de votre application.a activer seulement si vous avez un systeme de stacked Widget

        
            QByteArray nomData(nom.toUtf8(), 8);
            A.write_to_arduino(nomData);

        }

    // cas ou elle n'existe pas
    else if (!E.rfidExists(uid))
        {
            //inexistante
                QByteArray data1;
                data1.append('2');
                A.write_to_arduino(data1); // envoie 2 a arduino et enclenche /demarre le processus 2

                qDebug()<<"carte inexistante";

        }

    }
