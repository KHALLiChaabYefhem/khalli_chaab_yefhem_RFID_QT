bool Employer::rfidExists(QString uid)
{
    QSqlQuery query;
        query.prepare("SELECT RFID FROM EMPLOYER WHERE RFID = ?");
        query.addBindValue(uid);
        if (query.exec() && query.next()) {
            // If a row is returned, the uid exists in the database
            return true;
        }
    // If no row is returned, the uid does not exist in the database
    return false;
}

QString Employe::rfidName(QString uid)
{
    QSqlQuery query;
        query.prepare("SELECT NOM FROM EMPLOYER WHERE RFID = ?");
        query.addBindValue(uid);
        if (query.exec() && query.next()) {
            // If a row is returned, extract the value of the NOM attribute
            return query.value(0).toString();
        }
        // If no row is returned, return an empty string to indicate failure
        return "";
}
