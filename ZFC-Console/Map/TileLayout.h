//=============================================================================
// File:        TileLayout.h
//
// Description: 구조 검증을 통과한 불변(immutable) 타일 배치 타입 TileLayout 정의.
//
// History:     17/07/2026 + Created -- VicZero
//              17/07/2026 + 질의 함수 구현 분리 및 생성 정책 보완 -- VicZero
//
//=============================================================================

#pragma once

//========================================
// Project Includes
//========================================
#include "Core/Point.h"
#include "TileGrid.h"

//========================================
// Forward References
//========================================
class MapFactory;

//=============================================================================
//
// Synopsis:    TileLayout;
//                - MapFactory 의 구조 검증을 통과한 타일 배치를 소유한다.
//                - 생성 이후 구조를 변경할 수 없는 불변(immutable) 타입이다.
//                - TileLayout 객체가 존재한다는 사실 자체가 구조 검증 성공의 증거다.
//
//=============================================================================
class TileLayout
{
	///////////////////////////////////////////////////////////////////////
	// Friends
	///////////////////////////////////////////////////////////////////////
private:
	friend class MapFactory;

	///////////////////////////////////////////////////////////////////////
	// Private Member Data
	///////////////////////////////////////////////////////////////////////
private:
	// 검증을 통과한 타일 배치 원본. 값으로 직접 소유하며, 생성 후 변경하지 않는다.
	ZFC::TileGrid _tiles;

	///////////////////////////////////////////////////////////////////////
	// Construction / Destruction
	///////////////////////////////////////////////////////////////////////
private:
	// 검증이 끝난 원시 타일 데이터의 소유권을 인계받는다.
	explicit TileLayout(ZFC::TileGrid&& tiles);

public:
	TileLayout() = delete;

	// 큰 타일 배치의 의도하지 않은 전체 복사를 막는다.
	TileLayout(const TileLayout&) = delete;
	TileLayout& operator=(const TileLayout&) = delete;

	// 검증된 배치를 Map으로 전달할 수 있도록 이동은 허용한다.
	TileLayout(TileLayout&&) = default;
	TileLayout& operator=(TileLayout&&) = default;
	~TileLayout() = default;

	///////////////////////////////////////////////////////////////////////
	// Accessors / Queries
	///////////////////////////////////////////////////////////////////////
public:
	// 배치가 소유한 실제 타일 수를 기준으로 너비와 높이를 반환한다.
	ZFC::Point GetSize() const;

	// 내부 컨테이너에 접근하기 전에 좌표의 유효 범위를 판단한다.
	bool Contains(const ZFC::Point position) const;

	// 범위 밖 좌표는 유효한 지형이 없다는 의미의 TILE_NONE으로 처리한다.
	ZFC::TileType TileAt(const ZFC::Point position) const;
};
