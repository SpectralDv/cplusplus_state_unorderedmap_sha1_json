
#ifndef _REGEXJSON_H_
#define _REGEXJSON_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <typeinfo>


class ModelReadFile
{
private:
    std::string *arrLine;
public:
    ModelReadFile(){}
    ~ModelReadFile(){}
public:
    static std::string GetReadFile(std::string const & nameFile) 
    {
        std::string strLine;
        std::string strFile;
        std::ifstream in(nameFile);

        if(!(strLine.empty())){strLine.clear();}
        if(!(strFile.empty())){strFile.clear();}

        if(in.is_open())
        {
            while(std::getline(in,strLine))
            {
                strFile+=strLine;
            }
        }
        in.close();

        return strFile;
    }
   void WriteFile(std::string nameFile,std::string *arrLine,int size)
    {
        std::ofstream out;         
        out.open("test.json");  

        if (out.is_open())
        {
            for (int i = 0; i < size; i++)
            {
                out << arrLine[i] << std::endl;
            }
        }
        out.close();  
    }
    int GetPosLineCategory(std::string nameFile,std::string strCategory,std::string strData)
    {
        std::ifstream file(nameFile);
        std::string strLine;   
        int posLine = 0;
        arrLine = new std::string[1000];
        std::string state;

        while(getline(file,strLine))
        {

            arrLine[posLine] = strLine;
            posLine++;
            //ÉÝÅÔ ËÁÔÅÇÏÒÉÀ × ÆÁÊÌÅ
            if(strLine == "    \""+ strCategory +"\":")
            {
                state = "success";
                //delete[] arrLine;
                //return posLine;
            }
            else if(state == "success")
            {
                state = "";
                //ÄÏÂÏ×ÌÑÅÔ ÎÏ×ÕÀ ÓÔÒÏÞËÕ
                arrLine[posLine] = strData;
                posLine++;
            }
        }
        file.close();

        WriteFile(nameFile,arrLine,posLine);

        return 0;
    }
    int GetPosLineSubCategory(std::string nameFile,std::string strSubCategory,std::string strData)
    {

        std::ifstream file(nameFile);
        std::string strLine;   
        int posLine = 0;
        arrLine = new std::string[1000];
        std::string state;

        while(getline(file,strLine))
        {

            arrLine[posLine] = strLine;
            posLine++;
            //ÉÝÅÔ ËÁÔÅÇÏÒÉÀ × ÆÁÊÌÅ
            if(strLine == "        \""+ strSubCategory +"\":")
            {
                state = "success";
                //delete[] arrLine;
                //return posLine;
            }
            else if(state == "success")
            {
                //îõöîá ðòï÷åòëá îá ïäéîáëï÷ùå äáîîùå
                //é óäåìáôø úáðéóø ÷ âáúõ á îå ÷ æáêì
                state = "";
                //ÄÏÂÏ×ÌÑÅÔ ÎÏ×ÕÀ ÓÔÒÏÞËÕ
                arrLine[posLine] = strData;
                posLine++;
            }
        }
        file.close();

        WriteFile(nameFile,arrLine,posLine);

        return posLine;
    }
};

class ModelStr
{
public:
    std::string prefix;
    std::string suffix;
public:
    ModelStr(){}
    ~ModelStr(){}
};

class RegexJson 
{
public:
    RegexJson(){}
    ~RegexJson(){}
    void Log(std::string Tag,std::string str);
    // int TakeNumberFromFile(std::string const & nameFile, std::string word)
    // {
    //     std::string str = GetSquare(RegexParser(ModelReadFile::GetReadFile(nameFile),word));
    //     return stoi(str);
    // }
    static int TakeNumberFromFile(std::string const & nameFile, std::string word)
    {
        std::string str = Parser(ModelReadFile::GetReadFile(nameFile),word);
        return stoi(str);
    }
    static void GetPosFile(std::string const & nameFile, std::string word)
    {
        std::string str = Parser(ModelReadFile::GetReadFile(nameFile),word);
        //return stoi(str);
    }
private:
    static std::string Parser(std::string const & refstr,std::string word)
    {
        std::string str = RegexParser(refstr,word);
        return str;
    }
private:
    static std::string RegexParser(std::string const & refstr,std::string const & word) 
    {
        std::string str = refstr;
        std::regex reLeft(R"([\[])");
        std::regex reRight(R"([\]])");
        std::regex re{"(\")""("+word+")""(\"\\:\\[)"};
        std::regex reStr{"([.]*[^\"\\s])"};
        std::smatch match;

        for (std::sregex_iterator ibegin{str.begin(),str.end(),re},iend;ibegin!=iend;++ibegin)
        {
            if(std::regex_search(str, match, re)) 
            {
                str = match.suffix();
                std::regex_search(str,match,reRight);
                str = match.prefix();
                //break;
                return str;
            }
        }
        return "";
    }
    // ModelStr RegexParser(std::string const & refstr,std::string const & word)
    // {
    //     std::string str = refstr;
    //     std::regex re{"(\")""("+word+")""(\")"};
    //     std::smatch match;
    //     ModelStr mStr;

    //     for (std::sregex_iterator ibegin{str.begin(),str.end(),re},iend;ibegin!=iend;++ibegin)
    //     {
    //         if(std::regex_search(str, match, re)) 
    //         {
    //             mStr.suffix = match.suffix();
    //             mStr.prefix = match.prefix();
    //             //break;
    //             return mStr;
    //         }
    //     }
    //     return mStr;
    // }

    // //×ÏÚ×ÒÁÝÁÅÔ ÚÎÁÞÅÎÉÅ × Ë×ÁÄÒÔÙÎÁÈ ÓËÏÂËÁÈ
    // std::string GetSquare(ModelStr mStr)
    // {
    //     std::smatch match;
    //     std::regex reLeft(R"([\[])");
    //     std::regex reRight(R"([\]])");
    //     std::regex_search(mStr.suffix,match,reLeft);
    //     mStr.suffix = match.suffix();
    //     std::regex_search(mStr.suffix,match,reRight);
    //     return match.prefix();
    // }
    // ModelStr GetBraces(ModelStr mStr)
    // {
    //     std::smatch match; 
    //     std::regex reLeft(R"([{])");
    //     std::regex reRight(R"([}])");
    //     std::regex_search(mStr.suffix,match,reLeft);
    //     mStr.suffix = match.suffix();
    //     std::regex_search(mStr.suffix,match,reRight);
    //     mStr.suffix = match.prefix();
    //     return mStr;
    // }
};




#endif