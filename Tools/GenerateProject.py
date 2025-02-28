#--------------------------------------------------------------------------
# GenerateProject.py
#--------------------------------------------------------------------------

import sys
import os
import platform
import subprocess
from pathlib import Path
from colorama import Fore, Back, Style

PROJECT_NAME = "LTesto"
PROJECT_FILE = "LTesto.lua"

# Add 'Tools/Module' to path.
sys.path.append(os.path.join(os.path.dirname(__file__), "Module"))

import Module.ScriptUtils as Utils
from Module.PythonClass import PythonConfiguration
from Module.PremakeClass import PremakeConfiguration

PythonConfiguration.ValidatePackages()

# Change to project root if not already there.
bInProjectRoot = (Path.is_dir(Path("Source")) and Path.is_dir(Path("External")))
if not bInProjectRoot:
	os.chdir("..")
	if not Path.is_dir(Path("Source")):
		raise Exception("Failed to find project root directory")

Utils.PrintBanner(f"Generating Project: {PROJECT_NAME}", 60, Fore.WHITE, '=')

if platform.system() == "Windows":
	subprocess.call(["External/Premake5/bin/premake5.exe", "vs2022", f"--file={PROJECT_FILE}"])
else:
	raise Exception("Failed to run premake5 binary, unsupported platform")
