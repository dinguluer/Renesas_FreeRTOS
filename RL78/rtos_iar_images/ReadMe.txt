
small
 
Small model
 
The default attribute of both variables and functions is set to near.
 

medium
 
Medium model
 
The default attribute of variables is set to near and that for functions is set to far
 
===================

--code_model
Syntax
--code_model={near|n|far|f}Parameters
 
 near (default) Function calls reach the first 64 Kbytes of memory. 
far Function calls reach the entire 1 Mbyte memory. 

Description
Use this option to select the code model. If you do not select a code model, the compiler uses the default code model. Note that all modules of your application must use the same code model.
See also
Code models and memory attributes for function storage.
* 
Project>Options>General Options>Target>Code model


__CODE_MODEL__ == __CODE_MODEL_FAR__