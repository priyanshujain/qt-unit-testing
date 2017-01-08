
#include <QtTest>
#include <QtCore>
#include <QtGui>

class testCheckBox: public QObject
{
    Q_OBJECT
private slots:
    void testSignals();
};

void testCheckBox::testSignals()
{
    // You don't need to use an object created with "new" for
    // QSignalSpy, I just needed it in this case to test the emission
    // of a destroyed() signal.
    QCheckBox *xbox = new QCheckBox;

    // We are going to have two signal monitoring classes in use for
    // this test.
    // The first monitors the stateChanged() signal.
    // Also note that QSignalSpy takes a pointer to the object.
    QSignalSpy stateSpy( xbox, SIGNAL( stateChanged(int) ) );

    // Not strictly necessary, but I like to check that I have set up
    // my QSignalSpy correctly.
    QVERIFY( stateSpy.isValid() );

    // Now we check to make sure we don't have any signals already
    QCOMPARE( stateSpy.count(), 0 );

    // Here is a second monitoring class - this one for the
    // destroyed() signal.
    QSignalSpy destroyedSpy( xbox, SIGNAL( destroyed() ) );
    QVERIFY( destroyedSpy.isValid() );

    // A sanity check to verify the initial state
    // This also shows that you can mix normal method checks with
    // signal checks.
    QCOMPARE( xbox->checkState(), Qt::Unchecked );

    // Shouldn't already have any signals
    QCOMPARE( destroyedSpy.count(), 0 );

    // If we change the state, we should get a signal.
    xbox->setCheckState( Qt::Checked );
    QCOMPARE( stateSpy.count(), 1 );

    xbox->setCheckState( Qt::Unchecked );
    QCOMPARE( stateSpy.count(), 2 );

    xbox->setCheckState( Qt::PartiallyChecked );
    QCOMPARE( stateSpy.count(), 3 );

    // If we destroy the object, the signal should be emitted.
    delete xbox;

    // So the count of objects should increase.
    QCOMPARE( destroyedSpy.count(), 1 );

    // We can also review the signals that we collected
    // QSignalSpy is really a QList of QLists, so we take the first
    // list, which corresponds to the arguments for the first signal
    // we caught.
    QList<QVariant> firstSignalArgs = stateSpy.takeFirst();
    // stateChanged() only has one argument - an enumerated type (int)
    // So we take that argument from the list, and turn it into an integer.
    int firstSignalState = firstSignalArgs.at(0).toInt();
    // We can then check we got the right kind of signal.
    QCOMPARE( firstSignalState, static_cast<int>(Qt::Checked) );

    // check the next signal - note that takeFirst() removes from the list
    QList<QVariant> nextSignalArgs = stateSpy.takeFirst();
    // this shows another way of fudging the argument types
    Qt::CheckState nextSignalState = (Qt::CheckState)nextSignalArgs.at(0).toInt();
    QCOMPARE( nextSignalState, Qt::Unchecked );

    // and again for the third signal
    nextSignalArgs = stateSpy.takeFirst();
    nextSignalState = (Qt::CheckState)nextSignalArgs.at(0).toInt();
    QCOMPARE( nextSignalState, Qt::PartiallyChecked );
}

QTEST_MAIN(testCheckBox)
#include "tutorial5a.moc"
