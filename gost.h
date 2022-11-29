#ifndef GOST_H
#define GOST_H

#include <iostream>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <QString>
using std::cerr;
using std::endl;

class Gost
{
public:
    Gost(QString _text, QString _password);
    QString encrypt();
    QString decrypt();
private:
    unsigned char* key = (unsigned char*)"password";
    unsigned char* iv;
    unsigned char text[512];
    int text_len;


    int dciph_len = 0;
    unsigned char dciph;
    EVP_CIPHER_CTX* ctx;
    const EVP_CIPHER* cipher_gost;
    ENGINE* engine_gost;
};

#endif // GOST_H
