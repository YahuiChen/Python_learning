#include <iostream>
#include "checkBalanceSymbol.h"

void checklang(std::ifstream &ifile)
{
    if (ifile)
    {
        std::stack<char> check;
        //�����ջ�����׳��쳣
        check.push('!');
        //string testall("()[]{}*/");
        std::string pushin("([{*");
        std::string popout(")]}/");
        char prev = '\0';
        char curr;
        ifile >> curr;
        while (!ifile.eof())
        {
            //���ջ��Ϊע�ͷ�������ǳ��ַ�ע�ͣ�����ȫ������
            if (check.top() == '/')
            {
                if (prev == '*' && curr == '/')
                    check.pop();
            }
            else
            {
                //�����⵽��ʼ��־
                if (pushin.find(curr) != std::string::npos)
                {
                    //����ǵ���Ӧ����ֱ����ջ
                    if (curr != '*')
                        check.push(curr);
                    //�����ע������ջ
                    else if (prev == '/')
                        check.push('/');
                    //���򣬱�Ȼ��curr == '*', ��prev != '/'�����������������
                }
                //�����⵽������־
                else if (popout.find(curr) != std::string::npos)
                {
                    //�������������Ӧ����
                    //��ɶ�Ӧ�����������ɶ�Ӧ��������������
                    if (curr == ')')
                    {
                        if (check.top() == '(')
                            check.pop();
                        else
                            break;
                    }
                    else if (curr == ']')
                    {
                        if (check.top() == '[')
                            check.pop();
                        else
                            break;
                    }
                    else if (curr == '}')
                    {
                        if (check.top() == '{')
                            check.pop();
                        else
                            break;
                    }
                    //����Ƿ�ע��
                    else if (prev == '*')
                    {
                        if (check.top() == '/')
                            check.pop();
                        else
                            break;
                    }
                    //������Ƿ�ע�������κβ���
                }
            }
            //��ȡ��һ���ַ�
            prev = curr;

            ifile >> curr;
        }
        //���currδ�����ļ�β
        //��Ȼ����Ϊ����ĵ����Ŷ�Ӧ������ѭ��
        if (!ifile.eof())
        {
            std::cout << curr << " and " << check.top() << std::endl;
            std::cout << "Incorrect pop!" << std::endl;
        }
        //��������ļ�β��ջ�ײ��ǳ�ʼ��'!'
        //���к��ƽ���ȱʧ
        else if (check.top() != '!')
            std::cout << "Missing ending!" << std::endl;
        else
            std::cout << "Success" << std::endl;
        while (!check.empty())                    //�ͷſռ�
            check.pop();
    }
    else
        std::cout << "Cannot find stream!" << std::endl;
}