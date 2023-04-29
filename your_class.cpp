bool Employe::rfidExists(QString uid)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employe WHERE rfid_uid = ?");
    query.addBindValue(uid);
    query.exec();
    query.next();
    int count = query.value(0).toInt();
    return count > 0;
}


QString Employe::rfidName(QString uid)
    {
        QSqlQuery query;
        query.prepare("SELECT name FROM employe WHERE rfid_uid = ?");
        query.addBindValue(uid);
        query.exec();
        if (query.next()) {
            return query.value(0).toString();
        } else {
            return QString(); // return an empty string if no matching record is found
        }
    }
