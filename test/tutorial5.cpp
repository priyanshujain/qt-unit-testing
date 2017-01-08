#include <QtTest>
#include <QtCore>
#include <QtGui>

class testLabel: public QObject
{
    Q_OBJECT
private slots:
    void testChanges();
};

void testLabel::testChanges()
{
    QLabel label;

    // setNum() is a QLabel slot, but we can just call it like any
    // other method.
    label.setNum( 3 );
    QCOMPARE( label.text(), QString("3") );

    // clear() is also a slot.
    label.clear();
    QVERIFY( label.text().isEmpty() );
}

QTEST_MAIN(testLabel)
#include "tutorial5.moc"
