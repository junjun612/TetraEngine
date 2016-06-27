#pragma once

// ptr 를 Release 한 후 nullptr 화한다.
#define SAFE_RELEASE(ptr) \
if (ptr != nullptr) { ptr->Release(); ptr = nullptr; }

// ptr 를 delete 한 후 nullptr 화한다.
#define SAFE_DELETE(ptr) \
	if (ptr != nullptr) { delete ptr; ptr = nullptr; }

// SAFE_RELEASE -> SAFE_DELETE
#define SAFE_RELEASE_DELETE(ptr) \
	if (ptr != nullptr) { ptr->Release();  delete ptr; ptr = nullptr; }