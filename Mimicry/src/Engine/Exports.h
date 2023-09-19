#pragma once
#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef MimicryEngine_API
#define MimicryEngine_API __declspec(dllexport) 
#else
#define MimicryEngine_API __declspec(dllimport) 
#endif
#endif