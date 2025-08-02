#include "StageModule.h"

StageModule* StageModule::GetInstance(Board* board) {
	typedef StageModule* (*GetStageModule)(Board*);
	return ((GetStageModule)getActualOffset(0x7172EC))(board); // just get the first module and return that
}

StageModuleProperties* StageModule::GetProps() {
	Sexy::RtWeakPtr<StageModuleProperties> propsPtr;
	propsPtr.FromOther((Sexy::RtWeakPtr<StageModuleProperties>*) & this->m_propertySheetPtr);
	return propsPtr.Get();
}