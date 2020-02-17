# -*- coding: utf-8 -*-
"""
Created on Thu Sep 20 00:08:37 2018

@author: 鑫鑫玉川
"""

def load_txt(filename):
    f = open(filename,encoding='utf-8')
    if f==0:
        print("Error")
        return 
    word_dict=set()
    max_line=1
    for line in f:
       
        word=line.strip()
        word_dict.add(word)
        if len(word) > max_line:
            max_line = len(word)
    
    f.close()
    return max_line,word_dict
#python3解决了中文的读入输出问题，所以不用对读入的中文做encode的转化
def fmm_word_seg(sent,max_len,word_dict):
    begin=0
    word=[]
    while (begin < len(sent)):
        
        for end in range(begin+max_len,begin, -1):
                if sent[begin:end] in word_dict:
                    word.append(sent[begin:end])
                    begin = end
                    break
                
    print(word)
    return word
sentence="我爱北京天安门"

max_len,word_dict=load_txt('lexicon.dic')
word=fmm_word_seg(sentence,max_len,word_dict)

for w in word:
    print(w)