#include "gost.h"
#include <QDebug>
Gost::Gost(QString _text, QString _password)
{
    iv = ( unsigned char*) _password.data();
    std::copy(_text.toStdString().cbegin(), _text.toStdString().cend(), text);
    text_len = _text.length();
    cerr << "Program started" << endl;
    OPENSSL_add_all_algorithms_conf();
    ERR_load_ERR_strings();
    engine_gost = ENGINE_by_id("gost");
    if (!engine_gost)
    {
        char err[512];
        ERR_error_string(ERR_peek_last_error(), err);
        cerr << err << endl;
        exit(1);
    }
    cipher_gost = EVP_get_cipherbyname("gost89");
    if (EVP_CIPHER_mode(cipher_gost) == EVP_CIPH_CFB_MODE)
    {
        cerr << "Using GOST in CFB mode" << endl;
    }
    else cerr << "unknow mode" << endl;
}

QString Gost::encrypt()
{
    ctx = EVP_CIPHER_CTX_new();
    int init = EVP_EncryptInit_ex(ctx, cipher_gost, engine_gost, key, iv);
    int ciph_len = 0;
    unsigned char ciph[512];
    int enc = EVP_EncryptUpdate(ctx, ciph, &ciph_len, text, text_len);
//    std::cout.write((char*)ciph, ciph_len);
    EVP_CIPHER_CTX_free(ctx);
//    std::cout << "\n";
    return QString::fromLocal8Bit((char*)ciph,ciph_len);
}

QString Gost::decrypt()
{
    ctx = EVP_CIPHER_CTX_new();
    int init = EVP_DecryptInit_ex(ctx, cipher_gost, engine_gost, key, iv);
    int ciph_len = 0;
    unsigned char ciph[512];
    int enc = EVP_DecryptUpdate(ctx, ciph, &ciph_len, text, text_len);
    EVP_CIPHER_CTX_free(ctx);
    return QString::fromStdString(std::string (reinterpret_cast<char*>(ciph)));

}
