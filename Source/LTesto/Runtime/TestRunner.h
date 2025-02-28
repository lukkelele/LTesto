#pragma once

#include <filesystem>

#include "LTesto/Core/TestMacros.h"
#include "LTesto/Core/AutomationTest.h"

namespace LkEngine {

	/**
	 * LTestRunner
	 */
	class LTestRunner 
	{
	public:
		LTestRunner();
		virtual ~LTestRunner() = default;

		void Run();

	public:
		std::filesystem::path ResultsDir{};
	};

}
