import zipfile
import itertools
 
 
dictionaries = ['1', '2', '3', '4','5','6','7','8','9','0'] #����ƽ��ֵ�Ĺؼ��ַ������԰����Լ�������ӣ�
 
 
def allkeyword(): #���г��ַ�����4���ַ������
     allkey1 = itertools.product(dictionaries,repeat=12)
     allkey2 = (''.join(i) for i in allkey1)
     return allkey2
 
 
def trypassword (password):
     try:
     ZIPFILE = zipfile.ZipFile(r'D:\����\1.zip') #��������൱�ڶ���һ��ѹ���ļ�1.zip
     ZIPFILE.extractall(path=r'D:\12',pwd=password.encode('utf-8'))
     print(f"��ѹ�ɹ�,��ȷ����Ϊ��{password}")
     return True
     except:
     print(f"��ѹʧ��,��������Ϊ��{password}")
     return False
 
#��trypassword�������ص�True����Flase���ж������Ƿ���ֹ��
for pwd in allkeyword() :
     if trypassword(pwd):
     break