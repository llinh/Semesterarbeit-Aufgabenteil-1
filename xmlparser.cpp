#include "xmlparser.h"

#include <QObject>
#include <QDebug>
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>

XMLParser::XMLParser()
{
    Struct GlobalVarADT{
    int ID;
    QString text;
    GlobalVarADT globalVar;
    Struct Question{
    int questionID;
    QString questionText;
    QString answerText;
    }

}
