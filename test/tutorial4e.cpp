#include <QtTest>
#include <QtCore>


class testDate: public QObject
{
     Q_OBJECT
 private slots:
     void testValidity();
     void testValiditi();
 };

 void testDate::testValidity()
 {
     QTest::ignoreMessage(QtWarningMsg, "validity warning");
     qWarning("validity warning");
 }

 void testDate::testValiditi()
 {
     QTest::ignoreMessage(QtWarningMsg, "validity warning");
     qWarning("validiti warning");
 }

 QTEST_MAIN(testDate)
 #include "tutorial4e.moc"
