#pragma once

#include "CCollision.h"
#include "CInput.h"
#include "CLifeSpan.h"
#include "CShape.h"
#include "CTransform.h"
#include "CScore.h"
#include <tuple>

using ComponentTuple = std::tuple<CTransform, CCollision, CScore, CLifeSpan, CInput, CShape>;