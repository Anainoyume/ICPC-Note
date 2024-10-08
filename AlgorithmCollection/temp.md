## 卡特兰数

**引例1：**
姐姐和妹妹一起洗5个互不相同的碗，姐姐洗好的碗一个一个往上摞，每每再从最上面一个一个地拿走放入碗柜摞成一摞，姐姐一边洗，妹妹一边拿，那么妹妹摞好地碗一共有多少种不同地摞法。

**如何解决：**
我们可以使用 `W线图` 来解决这个问题。我们定义

```mermaid
graph LR  
A--text-->B
 ```

<svg height="250" width="200">
<line x1="0" y1="200" x2="200" y2="200"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="40" y1="160" x2="200" y2="160"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="80" y1="120" x2="200" y2="120"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="120" y1="80" x2="200" y2="80"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="160" y1="40" x2="200" y2="40"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="160" y1="40" x2="200" y2="40"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="200" y1="200" x2="200" y2="0"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="160" y1="40" x2="160" y2="200"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="120" y1="80" x2="120" y2="200"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="80" y1="120" x2="80" y2="200"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="40" y1="160" x2="40" y2="200"
style="stroke:rgb(255,255,255);stroke-width:1"/>
<line x1="0" y1="200" x2="200" y2="0"v
style="stroke:rgb(255,0,0);stroke-width:1"/>
<text x="60" y="230" fill="lightgray">[图1] W线图</text>
</svg>