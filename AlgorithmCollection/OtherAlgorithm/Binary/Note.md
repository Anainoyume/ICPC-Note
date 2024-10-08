## �����Ʊʼ�

�����ڽ��һ�ж����������ʱ�򣬶�����Ҫ��������һ���ַ������������������ǿ��Խ��� STL �� `bitset` ���ߡ�

�����򵥽���һЩλ������Ĳ�����
��������λ����Լ��Ͻ��в�����
$$
\bigcap~��~~~\bigcup~��~~~\complement~����~~~\Delta~�ԳƲ�
$$
�ֱ��Ӧ��
```cpp
& //��λ�� ~ ��
| //��λ�� ~ ��
~ //��λȡ�� ~ ����
^ //��λ��� ~ �ԳƲ�
```
��ôһЩ���ϵ����ʣ������ݳ�ԭ��Ҳ����������λ�������棺
$$
\mathrm{If~A\cup B = B,~Then~A\subset B}
$$
��ˣ��������Ҫ�ж�һ������������ `son` �Ƿ�Ϊ���������� `parent` ���Ӽ������ǾͿ���ʹ�ã�
```cpp
if ((son|parent) == parent) //���жϣ�ע�� λ����� ���ȼ����� �߼������
                            //��� son|parent Ҫ������

//��Ȼ����Ҳ�ǿ��Ե�
if ((son&parent) == son)
```

���Ǽ����ϵ����㣬��Ȼ���ǻ���һϵ�в�����
```cpp
(1 << (i-1)) & a    //�ж�a�ĵ�iλ(�����λ��ʼ��)�Ƿ����1
a | (1 << (i-1))    //��a�ĵ�iλ�ĳ�1
a & (~ (1 << i))    //��a�ĵ�iλ�ĳ�0
a & (a-1)           //��a�����һ��1ȥ��
a >> (i-1) & 1      //�ж�a�ĵ�iλ�Ƿ����1
a >> (i-1) | 0      //�ж�a�ĵ�iλ�Ƿ����0
(1 << i) - 1        //�õ�����Ϊi��ȫ��Ϊ1������
```