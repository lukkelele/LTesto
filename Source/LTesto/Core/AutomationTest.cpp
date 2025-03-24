#include "AutomationTest.h"

#include "LTesto/Runtime/TestManager.h"


namespace LkEngine::Test {

	int LAutomationTest::SuppressLogs = static_cast<int>(ELogLevel::Info);
	bool LAutomationTest::bElevateWarningsToErrors = false;

	LAutomationTest::LAutomationTest(const std::string& InName)
		: TestName(InName)
	{
		LOBJECT_REGISTER();
		LK_CORE_VERIFY(!TestName.empty());
		LK_TEST_TRACE_TAG("AutomationTest", "Created: {}", TestName);

		const bool bTestRegistration = LTestManager::Get().RegisterAutomationTest(TestName, this);
		if (!bTestRegistration)
		{
			LK_CORE_ERROR("Failed to register: '{}'", TestName);
		}
	}

	LAutomationTest::~LAutomationTest()
	{
		LK_TEST_TRACE_TAG("AutomationTest", "Destroying: {}", TestName);
		const bool bTestUnregistered = LTestManager::Get().UnregisterAutomationTest(TestName, this);
		if (!bTestUnregistered)
		{
			LK_CORE_ERROR("Test '{}' failed to unregister", TestName);
		}
	}

	void LAutomationTest::AddError(const std::string& ErrorMessage)
	{
		/* TODO: Add error event. */
		LK_TEST_TRACE_TAG(LK_FMT_LIB::format("AutomationTest::{}", GetName()), "Failed");
	}

	bool LAutomationTest::TestEqual(const int32_t Actual, const int32_t Expected, const char* Message)
	{
		if (Actual != Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestEqual(const int64_t Actual, const int64_t Expected, const char* Message)
	{
		if (Actual != Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestEqual(const std::size_t Actual, const std::size_t Expected, const char* Message)
	{
		if (Actual != Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestEqual(const float Actual, const float Expected, const char* Message)
	{
		if (Actual != Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterEqual(const int32_t Actual, const int32_t Expected, const char* Message)
	{
		if (Actual < Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterEqual(const int64_t Actual, const int64_t Expected, const char* Message)
	{
		if (Actual < Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterEqual(const std::size_t Actual, const std::size_t Expected, const char* Message)
	{
		if (Actual < Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterEqual(const float Actual, const float Expected, const char* Message)
	{
		if (Actual < Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterThan(const int32_t Actual, const int32_t Expected, const char* Message)
	{
		if (Actual <= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterThan(const int64_t Actual, const int64_t Expected, const char* Message)
	{
		if (Actual <= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterThan(const float Actual, const float Expected, const char* Message)
	{
		if (Actual <= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestGreaterThan(const std::size_t Actual, const std::size_t Expected, const char* Message)
	{
		if (Actual <= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessEqual(const int32_t Actual, const int32_t Expected, const char* Message)
	{
		if (Actual > Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessEqual(const int64_t Actual, const int64_t Expected, const char* Message)
	{
		if (Actual > Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessEqual(const float Actual, const float Expected, const char* Message)
	{
		if (Actual > Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessThan(const int32_t Actual, const int32_t Expected, const char* Message)
	{
		if (Actual >= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessThan(const int64_t Actual, const int64_t Expected, const char* Message)
	{
		if (Actual >= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}

	bool LAutomationTest::TestLessThan(const float Actual, const float Expected, const char* Message)
	{
		if (Actual >= Expected)
		{
			AddError(LK_FMT_LIB::format("Expected '{}' to be {}, but it was {}", Message, Expected, Actual));
			return false;
		}

		return true;
	}


}
