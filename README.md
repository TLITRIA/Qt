### 7.1.4 原对象系统

MOC提供
- 对象间通信的信号和槽机制
- 运行时类型信息
- 动态属性系统
元对象系统基于3个条件：
- 类继承自QObject
- 类的私有区声明Q_Object 类定义开始没有声明的时候是默认private
- MOC为QObject的子类实现元对象特性提供必要代码

元对象系统是为信号和槽引入的。但还提供其他特性：
- QObject::metaObject() 返回类的元对象
- QMetaObject::className() 运行时以字符串形式返回类名，不需要RTTI支持（C++编辑器原生的原型是类型信息）
- QObject::inheruts()返回继承树_上一个类的实例的信息
- tr trUtf8 进行字符串翻译实现国际化
- setProperty property 通过名字动态设置获取对象属性
- QMetaObject::newInstance() 构造类的一个新实例

动态类型转换 qonject_cast() 类型不兼容返回0

The MetaObject System 帮助

## 7.2 容器类
与STL相比，Qt中的容器类更轻量、安全、易用

### 7.2.1 Qt容器类介绍
- 顺序容器：QList QLinkedList QVector QStack QQueue
- 关联容器：QMap QMultiMap QHash QMultiHash QSet 
    Muliti容器适用一键多值的情况
- QCache QContiguousCache 缓存存储中对象的高级散列查找
