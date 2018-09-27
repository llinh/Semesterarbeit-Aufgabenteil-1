#ifndef PRODUCT_H
#define PRODUCT_H

#include "model.h"
#include "price.h"
#include "type.h"
#include "desc.h"

class Product
{
public:
    Product();
    QString id;
    Type type;
    Model model;
    Desc Desc;
    Price price;
};

#endif // PRODUCT_H
