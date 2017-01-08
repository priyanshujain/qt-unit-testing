#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testQdebug();
 };

 void testDate::testQdebug()
 {
     qWarning("warning");
     qDebug("debug");
     qCritical("critical");
 }

 QTEST_MAIN(testDate)
 #include "tutorial4d.moc"
