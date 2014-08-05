#ifndef TOPIX4_FAIRMQ_READOUT_H
#define TOPIX4_FAIRMQ_READOUT_H

#include "FairMQDevice.h"
#include "mrfcal_topix4.h"
#include "QString"
#include "QTextEdit"

class ToPix4_FairMQ_Readout: public FairMQDevice
{
public:
    enum {
      InputFile = FairMQDevice::Last,
      EventRate,
      EventSize,
      Last
    };
    ToPix4_FairMQ_Readout();
    virtual ~ToPix4_FairMQ_Readout();
    int CloseASICConnection();
    int OpenASICConnection(QString connectionparamter);
    virtual void SetProperty(const int key, const string& value, const int slot = 0);
    virtual string GetProperty(const int key, const string& default_ = "", const int slot = 0);
    virtual void SetProperty(const int key, const int value, const int slot = 0);
    virtual int GetProperty(const int key, const int default_ = 0, const int slot = 0);
    void SetOutputWindow(QTextEdit* window);


protected:
    virtual void Run();
    virtual void Init();
    int fEventSize;
    int fEventRate;

private:
    TMrfCal_Topix4 _topix4control;
    QTextEdit * _window;

};

#endif // TOPIX4_FAIRMQ_READOUT_H