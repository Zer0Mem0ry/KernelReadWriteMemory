NTSTATUS NTAPI MmCopyVirtualMemory
(
PEPROCESS SourceProcess,
PVOID SourceAddress,
PEPROCESS TargetProcess,
PVOID TargetAddress,
SIZE_T BufferSize,
KPROCESSOR_MODE PreviousMode,
PSIZE_T ReturnSize
);

NTSTATUS KeReadVirtualMemory(PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size)
{
    PSIZE_T Bytes;
	if (NT_SUCCESS(MmCopyVirtualMemory(Process, SourceAddress, PsGetCurrentProcess(),
		TargetAddress, Size, KernelMode, &Bytes)))
	{
		return STATUS_SUCCESS;
	}
	return STATUS_ACCESS_DENIED;
}

NTSTATUS KeWriteVirtualMemory(PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size)
{
	PSIZE_T Bytes;
	if (NT_SUCCESS(MmCopyVirtualMemory(PsGetCurrentProcess(), SourceAddress, Process,
		TargetAddress, Size, KernelMode, &Bytes))) {
		return STATUS_SUCCESS;
	}
	return STATUS_ACCESS_DENIED;
}

