![](https://cdn.luogu.com.cn/upload/image_hosting/26bfcuab.png)

设 $ OP = a, AP = b = k - a $，则 $ BP = ab, CP = 1 $。

由 $ OA \perp BC $ 可知，
$$
\begin{aligned}
    OB^2 + AC^2 &= OP^2 + AP^2 + BP^2 + CP^2 \\
    &= a^2 + b^2 + a^2b^2 + 1 \\
    &= \left(a + b\right)^2 - 2ab + a^2b^2 + 1 \\
    &= k^2 + \left(ab - 1\right)^2
\end{aligned}
$$

由上式可知，当 $ ab $ 最大，即 $ BP $ 最长时，$ OB^2 + AC^2 $ 取到最大值。

显然，当 $ P $ 在抛物线对称轴上时，$ BP $ 有最大值 $ \frac{k^2}{4} $，故

$$
\begin{aligned}
    \left(OB^2 + AC^2\right)_{\max} &= k^2 + \left(\frac{k^2}{4} - 1\right)^2 \\ 
    &= 4 \times \frac{k^2}{4} + \left(\frac{k^2}{4} - 1\right)^2 \\
    &= \left(\frac{k^2}{4} + 1\right)^2
\end{aligned}
$$
