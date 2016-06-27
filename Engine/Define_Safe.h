#pragma once

// ptr �� Release �� �� nullptr ȭ�Ѵ�.
#define SAFE_RELEASE(ptr) \
if (ptr != nullptr) { ptr->Release(); ptr = nullptr; }

// ptr �� delete �� �� nullptr ȭ�Ѵ�.
#define SAFE_DELETE(ptr) \
	if (ptr != nullptr) { delete ptr; ptr = nullptr; }

// SAFE_RELEASE -> SAFE_DELETE
#define SAFE_RELEASE_DELETE(ptr) \
	if (ptr != nullptr) { ptr->Release();  delete ptr; ptr = nullptr; }