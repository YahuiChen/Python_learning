# 是什么？
利用OCR、OpenCV等提取视频硬字幕
# 配置
## 百度OCR
在百度云开放平台注册，建应用得到APP_ID、API_KEY、SECRET_KEY，就可以用了。
每天前500次调用免费。
## config.py内容

    def getConfig(videoname):
        return {
            'APP_ID': '百度OCR APP_ID',
            'API_KEY': '百度OCR APP_KEY',
            'SECRET_KEY': '百度OCR SECRET_KEY',
            'videoDir': './video/' + videoname + '.mp4',
            'imgDir': './videoframes/' + videoname,
            'outputDir': './output/' + videoname + '/',

            'splitDuration': 1
        }

# 做了什么
从视频提取硬字幕要做以下事情：
## 1、视频切割
把视频切成若干张包含字幕的静态图片（这里是等距切，密度在config里splitDuration配置）。应在考虑调用成本的前提下尽量细切，保证字幕都切到（不用怕重复，这有去重）
## 2、图片OCR
百度OCR能返回所有识别结果的坐标。
## 3、去重
去重有两个目的：
一是防止结果重复；二是能把固定位置的文字收敛（比如台标），避免字幕定位错误。
## 4、字幕定位
每张图可能识别出若干组文字（每组都有位置信息），在获得所有切图OCR结果后，我们需要确定哪些是字幕的内容。

这里有两个假设：
1. 字幕的纵向位置基本不变
2. 字幕是整个视频中同一位置不同内容文字量最大的部分

有这两个假设：
1. 把top相近的识别结果分成一组
2. 去重后量最大的组就是字幕组

## 5、字幕分段（Todo）

# 测试结果
## 美妆教程
视频长度：4：51

切图密度：2s（145pic）

OCR时长：99s

识别内容：

    正确的化妆步骤,可以缩短化妆的时间,让你化妆更加有条理性,回常生活中,应用到裸妆的机会比较多,那么今天我就,教给大家裸妆的化妆步骤,让你轻轻松松快速搞定自已的妆容,美美的去上班,太好了快教教我们吧,下面开始今天的化妆教学了,大家一定要看好哦,希望大家会喜欢,今天模特呢是打好底妆了,下面呢开始化妆的第一步,就是先要画眉毛,因为模特前面的眉毛较重,我们人眉峰的位置开始画,要顺着眉毛生长的方向刻画,眉笔选用的颜色,要根据头发的颜色来选择,眉头呢可以画的淡一些,这样眉毛就刻画好了,大家可以看,接下来是眼妆的刻画,首先呢是眼影,要用裸色的眼影对眼部进行打底,因为今天呢画的是棵妆,但是呢我不想用大地色系的眼影,选用一款比较明媚的颜色,桃红色涂于眼窝上,淡淡的画层,然后选用金色的眼影涂于睫毛很部,然后选用金色的眼影涂号睡毛根部,向上进行除,但是范围呢不要超炒桃红色,接下来呢要用银白色在眉骨处进行提亮,这样上眼影就完成了,下面我们来画下眼影,下眼影呢要用金色的眼影,涂于后眼尾三分之一处,然后用桃红色,渐渐的向前进行一个过渡,同时可以用银色在眼角处进行提亮,这样眼影部分就打造完成了,眼妆的第二个步骤呢是眼线,下面我们来刻画眼线,要从眼头,画一条紧贴于睫毛根部的平行线,到眼尾的时候呢可以略粗一些,填满睫毛根部的缝隙,下眼线呢我们刻画到,后眼尾三分之一处,画的可以淡一些,这样眼线部分就完成了,大家可以看一下,眼妆的第三个步骤呢是瞳毛部分,首先要用睫毛夹把睫毛夹弯,然后是贴假睫毛,贴假睫毛的时候呢,一定要先贴假哦睫毛的中部,然后贴假睫毛的头部,最后贴假睫毛的末端,然后要用睫毛膏,对真假睫毛进行一个融合,同时呢下睫毛也要画上,这样眼部妆容就完成了,大家有没有看见明显的变化呀,化妆的第三个步骤呢是腮红部分,我们今天选用一款橘色的腮红,要涂于苹果肌上,苹果肌呢就是这个位置,比较凸起的部分,定要斜着画,这样才会使你的脸部,看上去比较有立体感,化妆的最后一个步骤呢是唇部,我们今天选用一个棵粉色的唇膏,涂于嘴唇上,这种颜色呢显得嘴唇特别的清新淡雅,下面我们来刻画另一边的脸
