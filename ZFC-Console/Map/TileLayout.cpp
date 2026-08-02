//=============================================================================
// File:        TileLayout.cpp
//
// Description: Implement TileLayout
//
// History:     17/07/2026 + Created -- VicZero
//
//=============================================================================

//========================================
// System Includes
//========================================
#include <utility>

//========================================
// Project Includes
//========================================
#include "TileLayout.h"

//******************************************************************************
//
// Private Member Functions
//
//******************************************************************************

//=============================================================================
// TileLayout::TileLayout
//=============================================================================
// Description: 구조 검증을 통과한 타일 그리드의 소유권을 인계받는다.
//
// Parameters:  ( ZFC::TileGrid&& tiles )
//
// Return:      N/A.
//
//=============================================================================
TileLayout::TileLayout(ZFC::TileGrid&& tiles)
	: _tiles(std::move(tiles))
{

}

//******************************************************************************
//
// Public Member Functions
//
//******************************************************************************

//=============================================================================
// TileLayout::GetSize
//=============================================================================
// Description: 배치의 크기(열 개수, 행 개수)를 구한다.
//
// Parameters:  None.
//
// Return:      ZFC::Point - x = 열 개수, y = 행 개수.
//
//=============================================================================
ZFC::Point TileLayout::GetSize() const
{
	int y = static_cast<int>(_tiles.size());
	int x = 0;

	// 이동된 원본에서도 front()를 호출하지 않도록 실제 행 존재 여부를 확인한다.
	if (!_tiles.empty())
	{
		x = static_cast<int>(_tiles.front().size());
	}

	return { x, y };
}

//=============================================================================
// TileLayout::Contains
//=============================================================================
// Description: 주어진 좌표가 배치의 실제 컨테이너 범위 안에 있는지 검사한다.
//
// Parameters:  ( const ZFC::Point position )
//
// Return:      bool - 범위 안이면 true, 아니면 false.
//
//=============================================================================
bool TileLayout::Contains(const ZFC::Point position) const
{
	// 음수 좌표를 부호 없는 컨테이너 인덱스로 변환하지 않는다.
	if (position.x < 0 || position.y < 0)
	{
		return false;
	}

	// TileLayout의 직사각형 불변 조건에 따라 첫 행의 너비가 전체 너비를 대표한다.
	if (static_cast<std::size_t>(position.y) < _tiles.size() &&
		static_cast<std::size_t>(position.x) < _tiles.front().size())
	{
		return true;
	}

	return false;
}

//=============================================================================
// TileLayout::TileAt
//=============================================================================
// Description: 주어진 좌표의 타일 타입을 반환한다.
//
// Parameters:  ( const ZFC::Point position )
//
// Return:      ZFC::TileType - 해당 좌표의 타일 타입. 범위 밖이면 TILE_NONE.
//
//=============================================================================
ZFC::TileType TileLayout::TileAt(const ZFC::Point position) const
{
	// 범위 밖 접근은 TILE_NONE으로 막아 잘못된 인덱싱을 방지한다.
	// TILE_NONE은 실제 지형이 아니라 유효한 타일이 없음을 나타낸다.
	if (!Contains(position))
	{
		return ZFC::TileType::TILE_NONE;
	}

	return _tiles[static_cast<std::size_t>(position.y)]
				 [static_cast<std::size_t>(position.x)];
}
