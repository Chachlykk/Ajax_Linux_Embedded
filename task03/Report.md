# task 2
оскільки файли досить великі, складно узагальнити результат. <br>
форматування необхідно застосувати до всіх файлів, такий результат видали обидві версіх clang-format <br>

# task 2 (a)

зміна версії форматеру не вплинула на форматування, git не виявив змін,тож немає чого комітити <br>
 
Основні зміни форматування включають переноси рядків, зміну кількості пробілів, вирівнювання дефайнів <br>

# task 3 (a)
 Language:        Cpp<br>
-# BasedOnStyle:  Chromium<br>
+AlignAfterOpenBracket: true<br>
 AccessModifierOffset: -1<br>
-AlignAfterOpenBracket: Align<br>
 AlignArrayOfStructures: None<br>
 AlignConsecutiveAssignments:<br>
   Enabled:         false<br>
   AcrossEmptyLines: false<br>
   AcrossComments:  false<br>
   AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
   PadOperators:    true<br>
 AlignConsecutiveBitFields:<br>
   Enabled:         false<br>
   AcrossEmptyLines: false<br>
   AcrossComments:  false<br>
   AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
   PadOperators:    false<br>
 AlignConsecutiveDeclarations:<br>
   Enabled:         false<br>
   AcrossEmptyLines: false<br>
   AcrossComments:  false<br>
   AlignCompound:   false<br>
+  AlignFunctionDeclarations: true<br>
+  AlignFunctionPointers: false<br>
   PadOperators:    false<br>
 AlignConsecutiveMacros:<br>
   Enabled:         false<br>
   AcrossEmptyLines: false<br>
   AcrossComments:  false<br>
   AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
   PadOperators:    false<br>
 AlignConsecutiveShortCaseStatements:<br>
   Enabled:         false<br>
   AcrossEmptyLines: false<br>
   AcrossComments:  false<br>
+  AlignCaseArrows: false<br>
   AlignCaseColons: false<br>
+AlignConsecutiveTableGenBreakingDAGArgColons:<br>
+  Enabled:         false<br>
+  AcrossEmptyLines: false<br>
+  AcrossComments:  false<br>
+  AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
+  PadOperators:    false<br>
+AlignConsecutiveTableGenCondOperatorColons:<br>
+  Enabled:         false<br>
+  AcrossEmptyLines: false<br>
+  AcrossComments:  false<br>
+  AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
+  PadOperators:    false<br>
+AlignConsecutiveTableGenDefinitionColons:<br>
+  Enabled:         false<br>
+  AcrossEmptyLines: false<br>
+  AcrossComments:  false<br>
+  AlignCompound:   false<br>
+  AlignFunctionDeclarations: false<br>
+  AlignFunctionPointers: false<br>
+  PadOperators:    false<br>
 AlignEscapedNewlines: Left<br>
 AlignOperands:   Align<br>
 AlignTrailingComments:<br>
+  AlignPPAndNotPP: true<br>
   Kind:            Always<br>
   OverEmptyLines:  0<br>
 AllowAllArgumentsOnNextLine: true<br>
 AllowAllParametersOfDeclarationOnNextLine: false<br>
+AllowBreakBeforeNoexceptSpecifier: Never<br>
+AllowBreakBeforeQtProperty: false<br>
 AllowShortBlocksOnASingleLine: Never<br>
+AllowShortCaseExpressionOnASingleLine: true<br>
 AllowShortCaseLabelsOnASingleLine: false<br>
+AllowShortCompoundRequirementOnASingleLine: true<br>
 AllowShortEnumsOnASingleLine: true<br>
 AllowShortFunctionsOnASingleLine: Inline<br>
 AllowShortIfStatementsOnASingleLine: Never<br>
 AllowShortLambdasOnASingleLine: All<br>
 AllowShortLoopsOnASingleLine: false<br>
+AllowShortNamespacesOnASingleLine: false<br>
 AlwaysBreakAfterDefinitionReturnType: None<br>
-AlwaysBreakAfterReturnType: None<br>
 AlwaysBreakBeforeMultilineStrings: true<br>
-AlwaysBreakTemplateDeclarations: Yes<br>
 AttributeMacros:<br>
   - __capability<br>
+  - absl_nonnull<br>
+  - absl_nullable<br>
+  - absl_nullability_unknown<br>
 BinPackArguments: true<br>
-BinPackParameters: false<br>
+BinPackLongBracedList: true<br>
+BinPackParameters: OnePerLine<br>
 BitFieldColonSpacing: Both<br>
+BracedInitializerIndentWidth: -1<br>
 BraceWrapping:<br>
   AfterCaseLabel:  false<br>
   AfterClass:      false<br>
@@ -75,27 +116,44 @@<br>
   SplitEmptyFunction: true<br>
   SplitEmptyRecord: true<br>
   SplitEmptyNamespace: true<br>
-BreakAfterAttributes: Never<br>
+BreakAdjacentStringLiterals: true<br>
+BreakAfterAttributes: Leave<br>
 BreakAfterJavaFieldAnnotations: false<br>
+BreakAfterOpenBracketBracedList: false<br>
+BreakAfterOpenBracketFunction: false<br>
+BreakAfterOpenBracketIf: false<br>
+BreakAfterOpenBracketLoop: false<br>
+BreakAfterOpenBracketSwitch: false<br>
+BreakAfterReturnType: None<br>
 BreakArrays:     true<br>
 BreakBeforeBinaryOperators: None<br>
+BreakBeforeCloseBracketBracedList: false<br>
+BreakBeforeCloseBracketFunction: false<br>
+BreakBeforeCloseBracketIf: false<br>
+BreakBeforeCloseBracketLoop: false<br>
+BreakBeforeCloseBracketSwitch: false<br>
 BreakBeforeConceptDeclarations: Always<br>
 BreakBeforeBraces: Attach<br>
 BreakBeforeInlineASMColon: OnlyMultiline<br>
+BreakBeforeTemplateCloser: false<br>
 BreakBeforeTernaryOperators: true<br>
+BreakBinaryOperations: Never<br>
 BreakConstructorInitializers: BeforeColon<br>
+BreakFunctionDefinitionParameters: false<br>
 BreakInheritanceList: BeforeColon<br>
 BreakStringLiterals: true<br>
+BreakTemplateDeclarations: Yes<br>
 ColumnLimit:     80<br>
 CommentPragmas:  '^ IWYU pragma:'<br>
 CompactNamespaces: false<br>
 ConstructorInitializerIndentWidth: 4<br>
 ContinuationIndentWidth: 4<br>
-Cpp11BracedListStyle: true<br>
+Cpp11BracedListStyle: AlignFirstComment<br>
 DerivePointerAlignment: false<br>
 DisableFormat:   false<br>
 EmptyLineAfterAccessModifier: Never<br>
 EmptyLineBeforeAccessModifier: LogicalBlock<br>
+EnumTrailingComma: Leave<br>
 ExperimentalAutoDetectBinPacking: false<br>
 FixNamespaceComments: true<br>
 ForEachMacros:<br>
@@ -127,6 +185,7 @@<br>
 IndentAccessModifiers: false<br>
 IndentCaseBlocks: false<br>
 IndentCaseLabels: true<br>
+IndentExportBlock: true<br>
 IndentExternBlock: AfterExternBlock<br>
 IndentGotoLabels: true<br>
 IndentPPDirectives: None<br>
@@ -138,32 +197,50 @@<br>
 InsertTrailingCommas: None<br>
 IntegerLiteralSeparator:<br>
   Binary:          0<br>
-  BinaryMinDigits: 0<br>
+  BinaryMinDigitsInsert: 0<br>
+  BinaryMaxDigitsRemove: 0<br>
   Decimal:         0<br>
-  DecimalMinDigits: 0<br>
+  DecimalMinDigitsInsert: 0<br>
+  DecimalMaxDigitsRemove: 0<br>
   Hex:             0<br>
+  HexMinDigitsInsert: 0<br>
+  HexMaxDigitsRemove: 0<br>
+  BinaryMinDigits: 0<br>
+  DecimalMinDigits: 0<br>
   HexMinDigits:    0<br>
 JavaScriptQuotes: Leave<br>
 JavaScriptWrapImports: true<br>
-KeepEmptyLinesAtTheStartOfBlocks: false<br>
-KeepEmptyLinesAtEOF: false<br>
+KeepEmptyLines:<br>
+  AtEndOfFile:     false<br>
+  AtStartOfBlock:  false<br>
+  AtStartOfFile:   true<br>
+KeepFormFeed:    false<br>
 LambdaBodyIndentation: Signature<br>
 LineEnding:      DeriveLF<br>
 MacroBlockBegin: ''<br>
 MacroBlockEnd:   ''<br>
+MainIncludeChar: Quote<br>
 MaxEmptyLinesToKeep: 1<br>
 NamespaceIndentation: None<br>
+NumericLiteralCase:<br>
+  ExponentLetter:  Leave<br>
+  HexDigit:        Leave<br>
+  Prefix:          Leave<br>
+  Suffix:          Leave<br>
 ObjCBinPackProtocolList: Never<br>
 ObjCBlockIndentWidth: 2<br>
 ObjCBreakBeforeNestedBlockParam: true<br>
 ObjCSpaceAfterProperty: false<br>
 ObjCSpaceBeforeProtocolList: true<br>
+OneLineFormatOffRegex: ''<br>
 PackConstructorInitializers: NextLine<br>
 PenaltyBreakAssignment: 2<br>
 PenaltyBreakBeforeFirstCallParameter: 1<br>
+PenaltyBreakBeforeMemberAccess: 150<br>
 PenaltyBreakComment: 300<br>
 PenaltyBreakFirstLessLess: 120<br>
 PenaltyBreakOpenParenthesis: 0<br>
+PenaltyBreakScopeResolution: 500<br>
 PenaltyBreakString: 1000<br>
 PenaltyBreakTemplateDeclaration: 10<br>
 PenaltyExcessCharacter: 1000000<br>
@@ -203,19 +280,25 @@<br>
     CanonicalDelimiter: pb<br>
     BasedOnStyle:    google<br>
 ReferenceAlignment: Pointer<br>
-ReflowComments:  true<br>
+ReflowComments:  Always<br>
 RemoveBracesLLVM: false<br>
+RemoveEmptyLinesInUnwrappedLines: false<br>
 RemoveParentheses: Leave<br>
 RemoveSemicolon: false<br>
 RequiresClausePosition: OwnLine<br>
 RequiresExpressionIndentation: OuterScope<br>
 SeparateDefinitionBlocks: Leave<br>
 ShortNamespaceLines: 1<br>
-SortIncludes:    CaseSensitive<br>
+SkipMacroDefinitionBody: false<br>
+SortIncludes:<br>
+  Enabled:         true<br>
+  IgnoreCase:      false<br>
+  IgnoreExtension: false<br>
 SortJavaStaticImport: Before<br>
 SortUsingDeclarations: LexicographicNumeric<br>
 SpaceAfterCStyleCast: false<br>
 SpaceAfterLogicalNot: false<br>
+SpaceAfterOperatorKeyword: false<br>
 SpaceAfterTemplateKeyword: true<br>
 SpaceAroundPointerQualifiers: Default<br>
 SpaceBeforeAssignmentOperators: true<br>
@@ -231,13 +314,15 @@<br>
   AfterFunctionDefinitionName: false<br>
   AfterFunctionDeclarationName: false<br>
   AfterIfMacros:   true<br>
+  AfterNot:        false<br>
   AfterOverloadedOperator: false<br>
+  AfterPlacementOperator: true<br>
   AfterRequiresInClause: false<br>
   AfterRequiresInExpression: false<br>
   BeforeNonEmptyParentheses: false<br>
 SpaceBeforeRangeBasedForLoopColon: true<br>
 SpaceBeforeSquareBrackets: false<br>
-SpaceInEmptyBlock: false<br>
+SpaceInEmptyBraces: Never<br>
 SpacesBeforeTrailingComments: 2<br>
 SpacesInAngles:  Never<br>
 SpacesInContainerLiterals: true<br>
@@ -246,6 +331,7 @@<br>
   Maximum:         -1<br>
 SpacesInParens:  Never<br>
 SpacesInParensOptions:<br>
+  ExceptDoubleParentheses: false<br>
   InCStyleCasts:   false<br>
   InConditionalStatements: false<br>
   InEmptyParentheses: false<br>
@@ -257,6 +343,7 @@<br>
 StatementMacros:<br>
   - Q_UNUSED<br>
   - QT_REQUIRE_VERSION<br>
+TableGenBreakInsideDAGArg: DontBreak<br>
 TabWidth:        8<br>
 UseTab:          Never<br>
 VerilogBreakBetweenInstancePorts: true<br>
@@ -266,5 +353,6 @@<br>
   - NS_SWIFT_NAME<br>
   - PP_STRINGIZE<br>
   - STRINGIZE<br>
+WrapNamespaceBodyWithEmptyLines: Leave<br>
 ...<br>
 <br>

# task 3(б)
 
Основні зміни форматування включають переноси рядків, зміну кількості пробілів, вирівнювання дефайнів <br>

# task3 (в)

diff --git a/task03/dummy/src/display_mode_core.c b/task03/dummy/src/display_mode_core.c<br>
index f38e447..c4767aa 100644<br>
--- a/task03/dummy/src/display_mode_core.c<br>
+++ b/task03/dummy/src/display_mode_core.c<br>
@@ -9549,7 +9549,7 @@ dml_bool_t dml_core_mode_support(struct display_mode_lib_st* mode_lib) {<br>
   CalculateSwathAndDETConfiguration(<br>
       &mode_lib->scratch,<br>
       CalculateSwathAndDETConfiguration_params); /* dml_bool_t<br>
-                                                    *ViewportSizeSupport */<br>
+                                                  *ViewportSizeSupport */<br>
 <br>
   s->MPCCombineMethodAsNeededForPStateChangeAndVoltage = false;<br>
   s->MPCCombineMethodAsPossible = false;<br>

# task 4
зміни стосуються переважно пробілів, відступів рядків, розташування фігурних дужок.<br>
різні версії clang-format майже не відрізняються
