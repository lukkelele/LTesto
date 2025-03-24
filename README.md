# LTesto

Test framework used by [LkEngine](https://github.com/lukkelele/LkEngine/tree/main).  

## Suites

### Core
Test suite for base engine functionality, non-graphics related.

* [ObjectPtr](https://github.com/lukkelele/LkEngine/blob/main/LkEngine/Test/Suite/Core/ObjectPtrTests.cpp)
* [Enum](https://github.com/lukkelele/LkEngine/blob/main/LkEngine/Test/Suite/Core/EnumTests.cpp)
* [Vector](https://github.com/lukkelele/LkEngine/blob/main/LkEngine/Test/Suite/Core/VectorTests.cpp) (Mathematics)
* [String](https://github.com/lukkelele/LkEngine/blob/main/LkEngine/Test/Suite/Core/StringTests.cpp)

---

## Framework

### Test Class (LAutomationTest)
LTesto use the class [LAutomationTest](./Source/LTesto/Core/AutomationTest.h) as a base for all tests.

### Test Manager (LTestManager)
The [LTestManager](./Source/LTesto/Runtime/TestManager.h) is responsible for registering every declared and defined test.  
This is done with the help of `LTestManager::AddToSuite` which does this by passing a creator function for each test instance.

---

## Test Declaration and Registration

The following macros can be found in [TestMacros.h](./Source/LTesto/Core/TestMacros.h).

### Declaration
```cpp
LK_DECLARE_AUTOMATION_TEST(TestName, Suite);
```

### Registration

```cpp
LK_DEFINE_AUTOMATION_TEST(TestName)
{
	/* ... Test Code ... */
	return true/false;
}
```

