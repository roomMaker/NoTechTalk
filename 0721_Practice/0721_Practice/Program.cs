//IEnumerator<int> TestIteratorMethod()
//{
//    yield return 1;
//    yield return 2;
//    yield return 3;
//    yield return 4;
//    yield return 5;
//    yield return 6;
//    yield return 7;
//    yield return 8;
//    yield return 9;
//    yield return 10;
//}

//IEnumerator<int> enumerator = TestIteratorMethod();

//while(enumerator.MoveNext())
//{
//    Console.WriteLine(enumerator.Current);
//}

class Base
{
    public virtual void Foo() { Console.WriteLine("Base의 Foo"); }
}


class Derived : Base
{
    public override void Foo()
    {
        base.Foo();
    }
}

abstract class AbstractBase
{
    public abstract void Foo();
}

class Derived2 : AbstractBase
{
    public override void Foo()
    {
        
    }
}
