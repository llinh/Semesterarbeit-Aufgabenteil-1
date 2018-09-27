#include <QCoreApplication>
#include <QtCore>
#include <QtXML>
#include <QDebug>
#include <product.h>
#include <model.h>
#include <type.h>
#include <desc.h>
#include <price.h>
#include <QCoreApplication>
#include <iostream>
using namespace std;
QList<Product> Read(QList<Product> productList)
{
    // Create a document to write XML
    QDomDocument document;

    // Open a file for reading
    QFile file("C:/Users/linhnguyen/Desktop/XMLManager/products.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";

    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";

        }
        file.close();
    }

    // Getting root element
    QDomElement root = document.firstChildElement();

    QDomNodeList products = root.elementsByTagName("product");
    // Looping through each dorm
    for(int i = 0; i < products.count(); i++)
    {
        QDomNode dormnode = products.at(i);
        if(dormnode.isElement())
        {
            QDomElement pro = dormnode.toElement();

            Product product;
            product.id = pro.attribute("id");

            Type type;

            //Type
            QDomNodeList nodes = pro.elementsByTagName("type");

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.type.typeId = e.attribute("typeId");
                }
            }

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.type.brand = e.attribute("brand");
                }
            }


            //model
            nodes = pro.elementsByTagName("model");

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.model.modelId = e.attribute("modelId");
                }
            }

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.model.gen = e.attribute("gen");
                }
            }


            //desc
            nodes = pro.elementsByTagName("desc");

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.Desc.dummy =  e.attribute("dummy");
                }
            }


            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.Desc.misc = e.attribute("misc");
                }
            }


            //price
            nodes = pro.elementsByTagName("price");

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.price.amount = e.attribute("amount");
                }
            }

            for(int i = 0; i < nodes.count(); i++)
            {
                QDomNode elm = nodes.at(i);
                if(elm.isElement())
                {
                    QDomElement e = elm.toElement();
                    product.price.currency = e.attribute("currency");
                }
            }

            productList.append(product);

        }
    }
    file.close();

    QFile file2("C:/Users/linhnguyen/Desktop/XMLManager/products.csv");
    if (!file2.open(QIODevice::ReadOnly)) {
        qDebug() << file2.errorString();

    }

        QStringList wordList;
        bool first = true;
        while (!file2.atEnd()) {
            QByteArray line = file2.readLine();
            Product product;

           if(first)
           {
               first = false;
           }
           else
           {
               QList<QByteArray> row = line.split(',');

               product.id = row[0];
               product.type.typeId = row[1];
               product.type.brand = row[2];
               product.model.modelId = row[3];
               product.model.gen = row[4];
               product.Desc.dummy = row[5];
               product.Desc.misc = row[6];
               product.price.amount = row[7];
               product.price.currency = row[8];

               productList.append(product);
           }

        }



        return productList;
}

void Write(QList<Product> productList, QString filename)
{
        // Create a document to write XML
        QDomDocument document;

        // DTD
        QDomElement dtd = document.createElement("!DOCTYPE Products SYSTEM 'Schema.dtd'");
         document.appendChild(dtd);
        // Making the root element
        QDomElement root = document.createElement("listProducts");

        document.appendChild(root);

         for(int i = 0; i < productList.length(); i++)
         {
             QDomElement product = document.createElement("product");
             product.setAttribute("id", productList[i].id);
             root.appendChild(product);

             QDomElement elem = document.createElement("type");
             elem.setAttribute("typeId", productList[i].type.typeId);
             elem.setAttribute("brand", productList[i].type.brand);
             product.appendChild(elem);

             elem = document.createElement("model");
             elem.setAttribute("modelId", productList[i].model.modelId);
             elem.setAttribute("gen", productList[i].model.gen);
             product.appendChild(elem);

             elem = document.createElement("type");
             elem.setAttribute("dummy", productList[i].Desc.dummy);
             elem.setAttribute("misc", productList[i].Desc.misc);
             product.appendChild(elem);

             elem = document.createElement("type");
             elem.setAttribute("amount", productList[i].price.amount);
             elem.setAttribute("currency", productList[i].price.currency);
             product.appendChild(elem);

         }

        QFile file("C:/Users/Hakeem/Documents/XMLManager/"+filename);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Open the file for writing failed";
        }
        else
        {
            QTextStream stream(&file);
            stream << document.toString();
            file.close();
            qDebug() << "Writing is done";
        }
}


char kommando[80];
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);



    bool running = true;

    while(running)
    {

        cout << "MENU\nWas möchten Sie tun?\n(1) XML und CSV import und zusammengefasst als XML exportieren: ";
        cin.getline(kommando,80,'\n');

        if (strncmp (kommando,"1",2) == 0)
        {
            cout << "Bitte geben Sie den gewuenschten Dateinamen an. Vergessen Sie das '.XML' nicht: ";
            cin.getline(kommando,80,'\n');

            QList<Product> productList;
            productList = Read(productList);
            QString filename(kommando);
            Write(productList, filename);
        }
        else
        {
            cout << "Kommando unbekannt...Forsetzten?(j): ";
            cin.getline(kommando,80,'\n');

            if (strncmp (kommando,"j",2) != 0)
            {
                running = false;
                cout << "Programm beendet";
            }

        }




    }



       return a.exec();
}
